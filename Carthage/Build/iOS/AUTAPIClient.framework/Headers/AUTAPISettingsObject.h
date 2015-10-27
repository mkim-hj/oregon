//
//  AUTAPISettingsObject.h
//  AUTAPIClient
//
//  Created by James Lawton on 10/7/15.
//  Copyright © 2015 Automatic Labs. All rights reserved.
//

@import Mantle;

NS_ASSUME_NONNULL_BEGIN

@interface AUTAPISettingsObject : MTLModel <MTLJSONSerializing>

/// Internal type of this object.
@property (nonatomic, readonly, copy) NSString *type;

/// User-visible title.
@property (nonatomic, readonly, copy) NSString *title;

/// The type matched by this class. To be called on concrete subtypes.
+ (NSString *)type;

@end

NS_ASSUME_NONNULL_END
