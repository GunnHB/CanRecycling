// Fill out your copyright notice in the Description page of Project Settings.


#include "CRSportsWheelFront.h"

UCRSportsWheelFront::UCRSportsWheelFront()
{
	WheelRadius = 39.f;					// 바퀴 반지름
	WheelWidth = 35.f;					// 바퀴 폭
	FrictionForceMultiplier = 1.5f;		// 마찰 배수

	MaxBrakeTorque = 5500.f;			// 브레이크 토크
	MaxHandBrakeTorque = 7000.f;		// 핸드 브레이크 토크
}
