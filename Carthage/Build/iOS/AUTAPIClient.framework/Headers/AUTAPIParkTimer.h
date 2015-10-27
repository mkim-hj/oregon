//
//  AUTAPIParkTimer.h
//  AUTAPIClient
//
//  Created by Engin Kurutepe on 25/09/15.
//  Copyright © 2015 Automatic Labs. All rights reserved.
//

#import <AUTAPIClient/AUTAPIObject.h>

NS_ASSUME_NONNULL_BEGIN

@interface AUTAPIParkTimer : AUTAPIObject

@property (readonly, nonatomic, assign) BOOL enabled;

@property (readonly, nonatomic, copy) NSDate *startDate;

@property (readonly, nonatomic, assign) NSTimeInterval duration;

@property (readonly, nonatomic, copy) NSDate *fireDate;

NS_ASSUME_NONNULL_END

@end
