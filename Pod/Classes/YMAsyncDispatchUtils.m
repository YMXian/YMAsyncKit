//
//  YMAsyncDispatchUtils.m
//  Pods
//
//  Created by 琰珂 郭 on 15/11/13.
//
//

#import "YMAsyncDispatchUtils.h"

#pragma mark - GCD dispatch_async

void dispatch_async_global(long identifier, YMAsyncVoidBlock block) {
  dispatch_async(dispatch_get_global_queue(identifier, 0), block);
}

void dispatch_async_low(YMAsyncVoidBlock block) {
  dispatch_async_global(DISPATCH_QUEUE_PRIORITY_LOW, block);
}

void dispatch_async_high(YMAsyncVoidBlock block) {
  dispatch_async_global(DISPATCH_QUEUE_PRIORITY_HIGH, block);
}

void dispatch_async_main(YMAsyncVoidBlock block) {
  dispatch_async(dispatch_get_main_queue(), block);
}

void dispatch_sync_main(YMAsyncVoidBlock block) {
  dispatch_sync(dispatch_get_main_queue(), block);
}

void dispatch_async_main_alt(YMAsyncVoidBlock block) {
  if ([NSThread isMainThread]) {
    block();
  } else {
    dispatch_async_main(block);
  }
}

void dispatch_sync_main_alt(YMAsyncVoidBlock block) {
  if ([NSThread isMainThread]) {
    block();
  } else {
    dispatch_sync_main(block);
  }
}

#pragma mark - GCD dispatch_after

void dispatch_after_seconds(dispatch_queue_t queue, NSTimeInterval seconds, YMAsyncVoidBlock block) {
  dispatch_after(dispatch_time(DISPATCH_TIME_NOW, (int64_t)(seconds * NSEC_PER_SEC)), queue, block);
}

void dispatch_main_after(NSTimeInterval seconds, YMAsyncVoidBlock block) {
  dispatch_after_seconds(dispatch_get_main_queue(), seconds, block);
}