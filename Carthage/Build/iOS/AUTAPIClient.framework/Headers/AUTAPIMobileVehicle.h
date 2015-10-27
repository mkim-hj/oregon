//
//  AUTAPIMobileVehicle.h
//  AUTAPIClient
//
//  Created by Engin Kurutepe on 24/09/15.
//  Copyright © 2015 Automatic Labs. All rights reserved.
//

#import <AUTAPIClient/AUTAPIVehicle.h>
#import <AUTAPIClient/AUTAPIPage.h>

@class AUTAPIPark;
@class AUTAPILocation;
@class AUTAPIVehicleState;

NS_ASSUME_NONNULL_BEGIN

AUTPageSubclassInterface(AUTAPIMobileVehicle)

/// A vehicle and its associated objects as synthesized from the mobile
/// aggregation API.
///
/// Its properties are inherited from AUTAPIVehicle, with additional synthesized
/// relationships to a park, location, and state added by the mobile aggregation
/// API.
@interface AUTAPIMobileVehicle : AUTAPIVehicle

/// The last known park of the receiver.
///
/// Nil if there is no last known park for the receiver.
@property (readonly, nonatomic, strong, nullable) AUTAPIPark *latestPark;

/// The last known location of the receiver.
///
/// Differs from latestPark in that the value could represent the receiver's
/// location while driving.
///
/// Nil if there is no last known location for the receiver.
@property (readonly, nonatomic, strong, nullable) AUTAPILocation *latestLocation;

/// The last known state of the receiver.
///
/// Nil if there is no last known park for the receiver.
@property (readonly, nonatomic, strong, nullable) AUTAPIVehicleState *state;

@end

NS_ASSUME_NONNULL_END
