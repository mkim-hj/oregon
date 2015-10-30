//
//  DashboardViewController.m
//  
//
//  Created by Maruchi Kim on 10/27/15.
//
//

#import "DashboardViewController.h"
#import "ViewController.h"
#import "SmogTestViewController.h"
#import "AppDelegate.h"

@interface DashboardViewController ()

@end

@implementation DashboardViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
    _emailLabel.text = _passedUsername;
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

- (IBAction)logOutPressed:(id)sender {
    AppDelegate * delegate = [[UIApplication sharedApplication] delegate];
    [delegate goToLogin];
}

@end
