//
//  AUTClient+AUTAPIDevice.h
//  AUTAPIClient
//
//  Created by Justin Spahr-Summers on 2015-04-20.
//  Copyright (c) 2015 Automatic Labs. All rights reserved.
//

#import <AUTAPIClient/AUTClient.h>

NS_ASSUME_NONNULL_BEGIN

@import ReactiveCocoa;
@class AUTAPIDevicePage;

@interface AUTClient (AUTAPIDevice)

/// Fetches information for the device that corresponds to the given ID.
///
/// Returns a signal which will send an AUTAPIDevice then complete, or else error.
- (RACSignal *)fetchDeviceWithID:(NSString *)deviceID;

/// Fetches information for all devices registered by user.
///
/// Returns a signal which will send an AUTAPIDevicePage then complete, or else
/// error.
/// The returned AUTAPIDevicePage can be passed to -fetchNextPageForPage: to
/// retrieve subsequent page if available.
- (RACSignal *)fetchDevices;

@end

NS_ASSUME_NONNULL_END
