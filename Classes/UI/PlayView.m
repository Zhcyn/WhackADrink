#import "PlayView.h"
@implementation PlayView
- (id)init
{
    self = [[[NSBundle mainBundle] loadNibNamed:@"PlayView" owner:self options:nil] objectAtIndex:0];
    if (self) {
        self.layer.cornerRadius = 5.f;
    }
    return self;
}
- (IBAction)playPressed:(id)sender {
    [self.delegate playPressed];
}
@end
