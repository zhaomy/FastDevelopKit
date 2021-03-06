//
//  FDChoiceButton.h
//  shanhuweidian
//
//  Created by zmy on 7/8/14.
//  Copyright (c) 2014 zmy. All rights reserved.
//

#import <UIKit/UIKit.h>

typedef enum {
    
    FDChoiceButtonStatusTypeUnselected = 0,
    FDChoiceButtonStatusTypeSelected   = 1,
    
}FDChoiceButtonStatusType;

typedef enum {
    
    FDChoiceTypeRadio = 0,
    FDChoiceTypeCheck = 1,
    
}FDChoiceType;


@protocol FDChoiceButtonDelegate;

@interface FDChoiceButton : UIButton

@property (nonatomic, strong) NSString                      *groupId;
@property (nonatomic, assign) NSUInteger                    index;
@property (nonatomic, assign) id <FDChoiceButtonDelegate>   delegate;
@property (nonatomic, assign) FDChoiceButtonStatusType      statusType;
@property (nonatomic, assign) FDChoiceType                  choiceType;

@property (nonatomic, copy  ) NSString   *nTitle;
@property (nonatomic, strong) UIColor    *nTitleColor;
@property (nonatomic, assign) CGFloat    nBorderWidth;
@property (nonatomic, strong) UIColor    *nBorderColor;


@property (nonatomic, copy  ) NSString   *sTitle;
@property (nonatomic, strong) UIColor    *sTitleColor;
@property (nonatomic, assign) CGFloat    sBorderWidth;
@property (nonatomic, strong) UIColor    *sBorderColor;

@property (nonatomic, strong) UILabel   *tLabel;

+ (instancetype)buttonWithFrame:(CGRect)frame
                  andChoiceType:(FDChoiceType)choiceType
                      withIndex:(NSUInteger)index
                        inGroup:(NSString*)groupId
              withSelectedImage:(UIImage*)selectedImage
                 andNormalImage:(UIImage*)normalImage;

+ (void)removedChoiceButtonFromMemoryInGroup:(NSString *)groupId;


- (void)setTitle:(NSString *)title
      titleColor:(UIColor *)titleColor
        forState:(UIControlState)state;

- (void)setBorderWidth:(CGFloat)borderWidth
           borderColor:(UIColor *)borderColor
              forState:(UIControlState)state;

@end

/**
 *  FDChoiceButtonDelegate
 */
@protocol FDChoiceButtonDelegate <NSObject>

@optional
- (void)fdChoiceButton:(FDChoiceButton *)fdChoiceButton
       selectedAtIndex:(NSUInteger)index
               inGroup:(NSString*)groupId;

@end



