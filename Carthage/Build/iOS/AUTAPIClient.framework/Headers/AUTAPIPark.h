//
//  AUTAPIPark.h
//  AUTAPIClient
//
//  Created by Engin Kurutepe on 25/09/15.
//  Copyright © 2015 Automatic Labs. All rights reserved.
//

#import <AUTAPIClient/AUTAPIObject.h>

@class AUTAPIAddress;
@class AUTAPILocation;
@class AUTAPIParkPhoto;
@class AUTAPIParkTimer;

NS_ASSUME_NONNULL_BEGIN

@interface AUTAPIPark : AUTAPIObject

@property (readonly, nonatomic, strong) AUTAPIAddress *address;

@property (readonly, nonatomic, strong) AUTAPILocation *location;

@property (readonly, nonatomic, copy) NSDate *date;

@property (readonly, nonatomic, strong) AUTAPIParkPhoto *photo;

@property (readonly, nonatomic, strong) AUTAPIParkTimer *timer;

@end

NS_ASSUME_NONNULL_END
