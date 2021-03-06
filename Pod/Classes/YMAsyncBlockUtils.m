//
//  YMAsyncBlockUtils.m
//  Pods
//
//  Created by 琰珂 郭 on 15/11/13.
//
//

#import "YMAsyncBlockUtils.h"

#pragma mark - Block manimulate

YMAsyncBOOLBlock YMAsyncCreateOnceBlock(YMAsyncVoidBlock inputBlock) {
  //  Create a flag
  __block BOOL clean = YES;
  
  return ^BOOL {
    //  Check the flag
    if (clean) {
      //  Clear the flag
      clean = NO;
      //  Invoke inputBlock
      inputBlock();
      return YES;
    }
    return NO;
  };
}

YMAsyncCompareBlock YMAsyncCreateAllBlock(NSUInteger count, YMAsyncVoidBlock inputBlock) {
  //  Create a counter
  __block NSUInteger n = 0;
  
  return ^NSComparisonResult {
    //  Increase the counter
    n++;
    //  Check the counter with count set
    if (n == count) {
      //  Invoke the inputBlock
      inputBlock();
      return NSOrderedSame;
    }
    return n < count ? NSOrderedDescending : NSOrderedAscending;
  };
}