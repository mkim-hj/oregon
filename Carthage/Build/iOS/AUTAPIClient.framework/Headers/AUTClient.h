//
//  AUTClient.h
//  AUTAPIClient
//
//  Created by Robert Böhnke on 24/02/15.
//  Copyright (c) 2015 Automatic Labs. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class AFOAuthCredential;
@class AUTAPIPage;
@class AUTRequest;
@class RACSignal;

typedef NS_OPTIONS(NSUInteger, AUTClientAuthorizationScopes) {
    AUTClientAuthorizationScopesPublic          = 1 << 0,
    AUTClientAuthorizationScopesUserProfile     = 1 << 1,
    AUTClientAuthorizationScopesUserFollow      = 1 << 2,
    AUTClientAuthorizationScopesLocation        = 1 << 3,
    AUTClientAuthorizationScopesCurrentLocation = 1 << 4,
    AUTClientAuthorizationScopesVehicleProfile  = 1 << 5,
    AUTClientAuthorizationScopesVehicleEvents   = 1 << 6,
    AUTClientAuthorizationScopesVehicleVin      = 1 << 7,
    AUTClientAuthorizationScopesTrip            = 1 << 8,
    AUTClientAuthorizationScopesBehavior        = 1 << 9,
    AUTClientAuthorizationScopesAutomatic       = 1 << 10
};

typedef NS_ENUM(NSInteger, AUTServerEnvironment) {
    /// Points at `https://api.automatic.com` and related servers
    AUTServerProductionEnvironment = 0,

    /// Points at `https://api.automatic.co` and related servers
    AUTServerStagingEnvironment,
};

@interface AUTClient : NSObject

/// A custom User-Agent HTTP header value used for overriding the
/// default one set by AFNetworking.
@property (readwrite, nonatomic, copy) NSString *customUserAgent;

/// The OAuth2 credential used to authenticate the receiver. This credential is
/// not persisted by the client, use `+[VALValet aut_storeCredential]` for that.
@property (readwrite, nonatomic, strong, nullable) AFOAuthCredential *credential;

/// The client ID used by the receiver.
@property (readonly, nonatomic, copy) NSString *clientID;

/// The client ID used by the receiver.
@property (readonly, nonatomic, copy) NSString *clientSecret;

- (instancetype)init NS_UNAVAILABLE;

/// Initializes the receiver to point to the production servers with a specific
/// client ID and secret.
- (instancetype)initWithClientID:(NSString *)clientID clientSecret:(NSString *)clientSecret;

/// Initializes the receiver with a new client ID and secret.
///
/// @param  server       The server set to access.
/// @param  clientID     The client ID to use. This argument must not be nil.
/// @param  clientSecret The client ID to use. This argument must not be nil.
/// @return A new `AUTClient` instance.
- (instancetype)initWithServer:(AUTServerEnvironment)serverEnvironment clientID:(NSString *)clientID clientSecret:(NSString *)clientSecret NS_DESIGNATED_INITIALIZER;

/// Converts `AUTClientAuthorizationScopes` to an array of `NSString`s that are
/// understood by the server.
+ (NSArray *)serializeScopes:(AUTClientAuthorizationScopes)scopes;

/// Attempts to authenticate the receiver with the server.
///
/// @param username The username to authenticate with. This argument must not be
///                 `nil`.
/// @param password The password to authenticate with. This argument must not be
///                 `nil`.
/// @param scopes   The scopes the client should request.
///
/// @return A signal that sends the credential and completes when the user was
///         successfully authenticated with the server, or sends an error
///         otherwise.
- (RACSignal *)authenticateWithUsername:(NSString *)username password:(NSString *)password scopes:(AUTClientAuthorizationScopes)scopes;

/// Convert a signal of `AUTAPIPage`s to a signal of signals of arrays of the
/// page's respective results.
///
/// This signal encapsulates the client and allows streams of pages to be
/// consumed without being aware of the receiver.
///
/// @param pageSignal A signal of `AUTAPIPage` instances. This argument must not be
///                   `nil`.
///
/// @return A signal of signals of the page's results. Subscribing to an inner
///         signal and sucessfully loading its single page with send a new
///         signal over the outer signal.
- (RACSignal *)asSignalOfSignals:(RACSignal *)pageSignal;

/// Fetches the next page for a given `AUTAPIPage`.
///
/// @param page The page to fetch. This argument must not be nil.
///
/// @return A signal that sends the next page for `page` and then completes, or
///         sends an error otherwise. If there is no next page, the signal
///         completes immediately.
- (RACSignal *)fetchNextPageForPage:(AUTAPIPage *)page;

/// Enqueues an `AUTRequest` request.
///
/// @param request The `AUTRequest` to perform. This argument must not be nil.
///
/// @return A signal that will send the results of the request, or send an error
///         otherwise.
- (RACSignal *)enqueueRequest:(AUTRequest *)request;

/// Returns a cold signal that sends next with a boolean value representing
/// whether this client is authenticated upon subscription, and subsequently
/// whenever the authentication status changes.
- (RACSignal *)authenticated;

/// Issue a grant token to hand off to another client.
- (RACSignal *)issueGrantTokenForClientID:(NSString *)clientID scopes:(AUTClientAuthorizationScopes)scopes;

/// A hot signal that sends updates to the reachability of the domain used for
/// API requests as NSNumber<AFNetworkReachabilityStatus>.
///
/// Does not error or complete.
///
/// Filters AFNetworkReachabilityStatusUnknown, sending next only when the
/// reachability status has been determined. If the reachability status has
/// already been determined, it is sent immediately upon subscription.
@property (readonly, nonatomic) RACSignal *reachabilityStatus;

@end

NS_ASSUME_NONNULL_END
