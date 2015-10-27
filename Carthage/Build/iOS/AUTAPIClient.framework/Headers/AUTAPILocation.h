//
//  AUTAPILocation.h
//  Automatic
//
//  Created by Robert Böhnke on 24/04/15.
//  Copyright (c) 2015 Automatic Labs. All rights reserved.
//

@import CoreLocation;
@import Mantle;

NS_ASSUME_NONNULL_BEGIN

//        "location": {
//            "accuracy_m": 2.1,
//            "created_at": "2015-09-25T13:52:46.902414+00:00",
//            "lat": 33.953667,
//            "lon": -118.396914
//        },


/// An `AUTAPILocation` encapulates a coordinate pair as well as an optional
/// address.
@interface AUTAPILocation : MTLModel <MTLJSONSerializing>

@property (readonly, nonatomic, assign) CLLocationCoordinate2D coordinate;

@property (readonly, nonatomic, assign) CLLocationAccuracy accuracy;

@property (readonly, nonatomic, copy) NSDate *date;

/// The name of the location, e.g. "Automatic HQ".
@property (readonly, nonatomic, copy, nullable) NSString *name;

@end

NS_ASSUME_NONNULL_END
