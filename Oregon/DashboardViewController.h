//
//  DashboardViewController.h
//  
//
//  Created by Maruchi Kim on 10/27/15.
//
//

#import <UIKit/UIKit.h>

@interface DashboardViewController : UIViewController
@property (nonatomic, retain) NSString *passedUsername;
@property (weak, nonatomic) IBOutlet UILabel *emailLabel;
@end
