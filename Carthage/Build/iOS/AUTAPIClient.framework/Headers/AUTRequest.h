//
//  AUTRequest.h
//  AUTAPIClient
//
//  Created by Robert Böhnke on 25/02/15.
//  Copyright (c) 2015 Automatic Labs. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/// `AUTRequest` encapsulates data associated with making a request against the
/// Automatic API that cannot be expressed with NSURLRequest, such as what class
/// if any should be used when parsing the results.
///
/// In the future this may be extended with other things, such as treating 404
/// status codes as empty responses instead of errors.
///
/// To facilitate building requests, it uses the builder pattern, e.g.:
///
///     [[[AUTRequest
///         GET:@"/path/resource/%@", someID]
///         parameters:@{
///             @foo": @123
///         }]
///         resultClass:nil];
///
@interface AUTRequest : NSObject <NSCopying>

/// The HTTP method used by this request.
@property (readonly, nonatomic, copy) NSString *method;

/// The parameters sent along with this request. Defaults to `nil`.
@property (readonly, nonatomic, copy, nullable) NSDictionary *parameters;

/// The relative path of the request. This path is relative to the path that the
/// `AUTClient` that executes this request was initialized with.
@property (readonly, nonatomic, copy) NSString *path;

/// The optional class to deserialize the response into. If this argument is not
/// nil, it must conform to `MTLJSONSerializing`.
@property (readonly, nonatomic, strong, nullable) Class resultClass;

/// The optional baseURL to signal that the request has a different base URL
/// than the AUTClient instance. nil if the default base of AUTClient should be used.
@property (readonly, nonatomic, copy, nullable) NSURL *baseURL;

#pragma mark - DSL

/// Builds a new `AUTRequest` that models a `GET` request to the given path.
+ (instancetype)GET:(NSString *)path, ... NS_FORMAT_FUNCTION(1,2);

/// Builds a new `AUTRequest` that models a `POST` request to the given path.
+ (instancetype)POST:(NSString *)path, ... NS_FORMAT_FUNCTION(1,2);

/// Builds a new `AUTRequest` that models a `PUT` request to the given path.
+ (instancetype)PUT:(NSString *)path, ... NS_FORMAT_FUNCTION(1,2);

/// Builds a new `AUTRequest` that models a `PATCH` request to the given path.
+ (instancetype)PATCH:(NSString *)path, ... NS_FORMAT_FUNCTION(1,2);

/// Builds a new `AUTRequest` that models a `DELETE` request to the given path.
+ (instancetype)DELETE:(NSString *)path, ... NS_FORMAT_FUNCTION(1,2);

/// Sets the parameters of the receiver, overwriting any previous ones.
- (instancetype)parameters:(nullable NSDictionary *)parameters;

/// Sets the result class of the receiver, overwriting any previous one.
- (instancetype)resultClass:(nullable Class)resultClass;

/// Sets the base URL of the receiver, overwriting any previous ones.
- (instancetype)baseURL:(nullable NSURL *)url;

@end

NS_ASSUME_NONNULL_END
