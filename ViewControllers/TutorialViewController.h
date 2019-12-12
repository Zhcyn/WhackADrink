#import <UIKit/UIKit.h>
typedef enum {
    TutorialTypeTimed60 = 0,
    TutorialTypeTimed120,
    TutorialTypeLives,
    TutorialTypeMain
} TutorialType;
@interface TutorialViewController : UIViewController
@property (weak, nonatomic) IBOutlet UILabel *scoreLabel;
@property (weak, nonatomic) IBOutlet UIImageView *backgroundImageView;
@property (nonatomic, assign) TutorialType type;
@end
