// Fill out your copyright notice in the Description page of Project Settings.


#include "CRSportsWheelRear.h"

UCRSportsWheelRear::UCRSportsWheelRear()
{
	WheelRadius = 40.f;					// 바퀴 반지름
	WheelWidth = 40.f;					// 바퀴 폭
	FrictionForceMultiplier = 3.f;		// 마찰 배수

	CorneringStiffness = 2000.f;

	// 미끄러짐 임계 값
	SlipThreshold = 100.f;
	SkidThreshold = 100.f;

	MaxSteerAngle = 0.f;				// 조향 각도
	MaxHandBrakeTorque = 7000.f;		// 핸드 브레이크 토크
}
