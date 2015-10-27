//
//  AUTAPIVehicleState.h
//  AUTAPIClient
//
//  Created by Engin Kurutepe on 29/09/15.
//  Copyright © 2015 Automatic Labs. All rights reserved.
//

@import Mantle;

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSInteger, AUTVehicleStateValue) {
    AUTVehicleStateParked,
    AUTVehicleStateDriving
};

extern NSString * const kAUTVehicleStateParked;
extern NSString * const kAUTVehicleStateDriving;

@interface AUTAPIVehicleState : MTLModel <MTLJSONSerializing>

@property (readonly, nonatomic, copy) NSDate *date;

@property (readonly, nonatomic, assign) AUTVehicleStateValue state;

@end

NS_ASSUME_NONNULL_END
