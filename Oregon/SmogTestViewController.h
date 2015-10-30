//
//  SmogTestViewController.h
//  Oregon
//
//  Created by Maruchi Kim on 10/28/15.
//  Copyright © 2015 Maruchi Kim. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "AutomaticAdapter/AutomaticAdapter.h"

@interface SmogTestViewController : UIViewController
@property (nonatomic, retain) ALELM327Session *currentSession;

- (void) pollLink;

@end
