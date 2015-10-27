//
//  AUTAPIParkPhoto.h
//  AUTAPIClient
//
//  Created by Engin Kurutepe on 25/09/15.
//  Copyright © 2015 Automatic Labs. All rights reserved.
//

#import <AUTAPIClient/AUTAPIObject.h>

NS_ASSUME_NONNULL_BEGIN

/// Defines a barebones model for a photo linked to a park. The photo itself can
/// be accessed through the URL property inherited from AUTAPIObject.
@interface AUTAPIParkPhoto : AUTAPIObject

@property (readonly, nonatomic, copy) NSDate *date;

@end

NS_ASSUME_NONNULL_END
