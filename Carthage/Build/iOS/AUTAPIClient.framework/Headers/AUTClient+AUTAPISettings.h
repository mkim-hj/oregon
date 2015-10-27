//
//  AUTClient+AUTAPISettings.h
//  AUTAPIClient
//
//  Created by James Lawton on 10/1/15.
//  Copyright © 2015 Automatic Labs. All rights reserved.
//

#import <AUTAPIClient/AUTClient.h>

NS_ASSUME_NONNULL_BEGIN

@interface AUTClient (AUTAPISettings)

/// Fetch settings. Sends `AUTAPISettings` and completes, or errors.
- (RACSignal *)fetchSettings;

/// Update a setting. `value` must be encodable as JSON.
- (RACSignal *)updateSetting:(NSURL *)settingURL value:(id)value;

@end

NS_ASSUME_NONNULL_END
