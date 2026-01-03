// Fill out your copyright notice in the Description page of Project Settings.


#include "CRSportsWheelFront.h"

UCRSportsWheelFront::UCRSportsWheelFront()
{
	WheelRadius = 39.f;					// 바퀴 반지름
	WheelWidth = 35.f;					// 바퀴 폭
	FrictionForceMultiplier = 2.5f;		// 마찰 배수

	CorneringStiffness = 2000.f;

	MaxBrakeTorque = 6500.f;			// 브레이크 토크
	MaxHandBrakeTorque = 8500.f;		// 핸드 브레이크 토크
}
