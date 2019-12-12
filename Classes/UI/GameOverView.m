#import "GameOverView.h"
@implementation GameOverView
- (id)init
{
    self = [[[NSBundle mainBundle] loadNibNamed:@"GameOverView" owner:self options:nil] objectAtIndex:0];
    if (self) {
    }
    return self;
}
- (void)displayed
{
    [self performSelector:@selector(showMenuOptions) withObject:nil afterDelay:0.5];
}
- (void)showMenuOptions
{
    self.startNewGameButton.enabled = YES;
    self.leaderboardButton.enabled = YES;
    self.mainMenuButton.enabled = YES;
}
- (IBAction)newGamePressed:(id)sender
{
    [self.delegate gameOverViewNewGame:self];
}
- (IBAction)mainMenuPressed:(id)sender
{
    [self.delegate gameOverViewMainMenu:self];
}
- (IBAction)leaderboardPressed:(id)sender
{
    [self.delegate leaderboardPressed:self];
}
@end
