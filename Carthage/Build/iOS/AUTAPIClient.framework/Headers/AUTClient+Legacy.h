//
//  AUTClient_Legacy.h
//  AUTAPIClient
//
//  Created by Sylvain Rebaud on 5/6/15.
//  Copyright (c) 2015 Automatic Labs. All rights reserved.
//

#import <Foundation/Foundation.h>

#import <AUTAPIClient/AUTClient.h>

NS_ASSUME_NONNULL_BEGIN

@class RACSignal;
@class AUTLegacyCredential;

@interface AUTClient (Legacy)

@property (atomic, copy, nullable) AUTLegacyCredential *legacyCredential;

/// A signal that sends the legacy credential and completes when the user was
/// successfully authenticated with the server, or sends an error otherwise.
- (RACSignal *)authenticateLegacyWithUsername:(NSString *)username password:(NSString *)password;

/// A signal that sends a request to a legacy server
- (RACSignal *)enqueueLegacyRequest:(AUTRequest *)request;

- (RACSignal *)enqueueLegacyRequest:(NSURLRequest *)request resultClass:(Class __nullable)resultClass;

/// Returns a cold signal that sends next with a boolean value representing
/// whether this client is authenticated with the legacy API upon subscription,
/// and subsequently whenever the authentication status changes.
- (RACSignal *)authenticatedWithLegacy;

/// Returns a cold signal that sends next with a boolean value representing
/// whether this client is authenticated with both the legacy API _and_ the
/// newton API upon subscription, and subsequently whenever the combined
/// authentication status changes.
- (RACSignal *)authenticatedWithLegacyAndNewton;

/// The base URL for the legacy API
- (NSURL *)legacyAPIBaseURL;

/// A hot signal that sends updates to the reachability of the client's
/// legacyAPIBaseURL's domain as NSNumber<AFNetworkReachabilityStatus>.
///
/// Does not error or complete.
///
/// Filters AFNetworkReachabilityStatusUnknown, sending next only when the
/// reachability status has been determined. If the reachability status has
/// already been determined, it is sent immediately upon subscription.
@property (readonly, nonatomic) RACSignal *legacyReachabilityStatus;

@end

NS_ASSUME_NONNULL_END
