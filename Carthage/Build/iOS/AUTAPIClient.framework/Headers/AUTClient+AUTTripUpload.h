//
//  AUTClient+AUTTripUpload.h
//  AUTAPIClient
//
//  Created by Justin Spahr-Summers on 2015-06-18.
//  Copyright (c) 2015 Automatic Labs. All rights reserved.
//

#import <AUTAPIClient/AUTClient.h>

@class AUTAPITripChunk;
@import ReactiveCocoa;

NS_ASSUME_NONNULL_BEGIN

/// The maximum accepted size for trip chunks by the API, in bytes.
extern const NSUInteger AUTMaximumTripChunkSize;

@interface AUTClient (AUTTripUpload)

/// Uploads one chunk from a batch of trip data.
///
/// Returns a signal which will send an AUTAPILegacyResponse and then complete or
/// error.
- (RACSignal *)uploadTripChunk:(AUTAPITripChunk *)tripChunk;

/// Returns a signal that internally automatically retries uploading the
/// specified trip chunk until it is successful or an unrecoverable error
/// occurs.
///
/// If the upload was successful, sends a next of AUTAPILegacyResponse and
/// completes. If an unrecoverable error occurs, errors with the unrecoverable
/// error. If a recoverable error occurs, internally retries the upload after a
/// back-off interval.
- (RACSignal *)autoretryingUploadTripChunk:(AUTAPITripChunk *)tripChunk;

/// @see autoretryingUploadTripChunk: for signal contract.
///
/// @param reachabilityStatus A signal that sends AFNetworkReachabilityStatus,
///        typically for use when testing.
///
/// @param errors A subject that sends the errors that occur during internal
///        retries.
- (RACSignal *)autoretryingUploadTripChunk:(AUTAPITripChunk *)tripChunk reachabilityStatus:(RACSignal *)reachabilityStatus errors:(nullable RACSubject *)errors;

@end

/// The amount of time than an autoretrying trip chunk upload should wait before
/// retrying after a recoverable error, given the number of retries that have
/// occurred so far.
NSTimeInterval AUTTripUploadAutoretryBackOffInterval(NSUInteger retry);

NS_ASSUME_NONNULL_END
