#import <UIKit/UIKit.h>
@class GamePanelViewController;
@protocol GamePanelViewControllerDelegate <NSObject>
- (void)gamePanel:(GamePanelViewController *)viewController updatedScore:(NSInteger)score;
@end
@interface GamePanelViewController : UIViewController
@property (nonatomic, weak) id<GamePanelViewControllerDelegate> delegate;
@property (nonatomic, assign) BOOL useShorterThreshold;
- (void)startGame;
- (void)stopGame;
- (void)showPopupWithType:(NSInteger)type atIndex:(NSInteger)index;
@end
