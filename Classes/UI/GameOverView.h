#import <UIKit/UIKit.h>
@class GameOverView;
@protocol GameOverViewDelegate <NSObject>
- (void)gameOverViewMainMenu:(GameOverView *)gameOverView;
- (void)gameOverViewNewGame:(GameOverView *)gameOverView;
- (void)leaderboardPressed:(GameOverView *)view;
@end
@interface GameOverView : UIView
@property (nonatomic, weak) id<GameOverViewDelegate> delegate;
@property (weak, nonatomic) IBOutlet UILabel *scoreLabel;
@property (weak, nonatomic) IBOutlet UIButton *startNewGameButton;
@property (weak, nonatomic) IBOutlet UIButton *mainMenuButton;
@property (weak, nonatomic) IBOutlet UIButton *leaderboardButton;
- (void)displayed;
- (IBAction)newGamePressed:(id)sender;
- (IBAction)mainMenuPressed:(id)sender;
- (IBAction)leaderboardPressed:(id)sender;
@end
