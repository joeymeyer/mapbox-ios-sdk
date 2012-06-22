//
//  RMMapTiledLayerView.h
//  MapView
//
//  Created by Thomas Rasch on 17.08.11.
//  Copyright (c) 2011 Alpstein. All rights reserved.
//

@class RMMapView, RMMapTiledLayerView;

@protocol RMMapTiledLayerViewDelegate <NSObject>
@optional

// points are in the mapview coordinate space
- (void)mapTiledLayerView:(RMMapTiledLayerView *)aTiledLayerView singleTapAtPoint:(CGPoint)aPoint;
- (void)mapTiledLayerView:(RMMapTiledLayerView *)aTiledLayerView doubleTapAtPoint:(CGPoint)aPoint;
- (void)mapTiledLayerView:(RMMapTiledLayerView *)aTiledLayerView twoFingerSingleTapAtPoint:(CGPoint)aPoint;
- (void)mapTiledLayerView:(RMMapTiledLayerView *)aTiledLayerView longPressAtPoint:(CGPoint)aPoint;

@end

//Used for drawing extensive graphics on top of the map layer
@protocol RMMapTiledLayerViewSurlayerDrawer <NSObject>

@optional
- (void)mapTiledLayerView:(RMMapTiledLayerView *)aTiledLayerView drawSurlayer:(CALayer *)layer inContext:(CGContextRef)context;

@end

@interface RMMapTiledLayerView : UIView
{
    id <RMMapTiledLayerViewDelegate> delegate;
    id <RMMapTiledLayerViewSurlayerDrawer> surlayerDrawer;
    RMMapView *mapView;
}

@property (nonatomic, assign) id <RMMapTiledLayerViewDelegate> delegate;
@property (nonatomic, assign) id <RMMapTiledLayerViewSurlayerDrawer> surlayerDrawer;

- (id)initWithFrame:(CGRect)frame mapView:(RMMapView *)aMapView;

@end
