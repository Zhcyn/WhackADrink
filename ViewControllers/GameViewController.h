#import "LivesView.h"
typedef enum {
    GameTypeTimed60 = 0,
    GameTypeTimed120,
    GameTypeLives
} GameType;
@interface GameViewController : UIViewController
@property (weak, nonatomic) IBOutlet UILabel *scoreLabel;
@property (weak, nonatomic) IBOutlet UILabel *timeLabel;
@property (nonatomic, weak) IBOutlet LivesView *livesView;
@property (weak, nonatomic) IBOutlet UIImageView *backgroundImageView;
@property (nonatomic, assign) NSInteger timerLength;
@property (nonatomic, assign) GameType gameType;
@end
