@interface MenuViewController : UIViewController
@property (weak, nonatomic) IBOutlet UIButton *timed60Button;
@property (weak, nonatomic) IBOutlet UIButton *timed120Button;
@property (weak, nonatomic) IBOutlet UIImageView *backgroundImageView;
- (IBAction)timedPressed:(id)sender;
- (IBAction)livesPressed:(id)sender;
- (IBAction)leaderboardsPressed:(id)sender;
@end
