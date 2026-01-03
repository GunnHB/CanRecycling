// Fill out your copyright notice in the Description page of Project Settings.


#include "CRSportsKart.h"

#include "ChaosWheeledVehicleMovementComponent.h"
#include "Wheels/Sports/CRSportsWheelFront.h"
#include "Wheels/Sports/CRSportsWheelRear.h"

ACRSportsKart::ACRSportsKart()
{
	// set up the chassis
	VehicleMovementComponent->ChassisHeight = 144.f;		// 차체 높이
	VehicleMovementComponent->DragCoefficient = .31f;		// 공기 저항 계수

	// set up the wheels
	VehicleMovementComponent->bLegacyWheelFrictionPosition = true;
	VehicleMovementComponent->WheelSetups.SetNum(4);

	// 바퀴 클래스 세팅
	VehicleMovementComponent->WheelSetups[0].WheelClass = UCRSportsWheelFront::StaticClass();
	VehicleMovementComponent->WheelSetups[0].BoneName = FName(TEXT("Phys_Wheel_FL"));
	VehicleMovementComponent->WheelSetups[0].AdditionalOffset = FVector::ZeroVector;
	
	VehicleMovementComponent->WheelSetups[1].WheelClass = UCRSportsWheelFront::StaticClass();
	VehicleMovementComponent->WheelSetups[1].BoneName = FName(TEXT("Phys_Wheel_FR"));
	VehicleMovementComponent->WheelSetups[1].AdditionalOffset = FVector::ZeroVector;

	VehicleMovementComponent->WheelSetups[2].WheelClass = UCRSportsWheelRear::StaticClass();
	VehicleMovementComponent->WheelSetups[2].BoneName = FName(TEXT("Phys_Wheel_BL"));
	VehicleMovementComponent->WheelSetups[2].AdditionalOffset = FVector::ZeroVector;
	
	VehicleMovementComponent->WheelSetups[3].WheelClass = UCRSportsWheelRear::StaticClass();
	VehicleMovementComponent->WheelSetups[3].BoneName = FName(TEXT("Phys_Wheel_BR"));
	VehicleMovementComponent->WheelSetups[3].AdditionalOffset = FVector::ZeroVector;

	// set up the engine
	VehicleMovementComponent->EngineSetup.MaxTorque = 750.f;					// 엔진 힘
	VehicleMovementComponent->EngineSetup.MaxRPM = 7000.f;						// 분 당 회전 수 (rpm)
	VehicleMovementComponent->EngineSetup.EngineIdleRPM = 900.f;				// 대기 시 rpm
	VehicleMovementComponent->EngineSetup.EngineBrakeEffect = .2f;				// 엔진 브레이크 정도
	VehicleMovementComponent->EngineSetup.EngineRevUpMOI = 5.f;					// rpm 저항 값
	VehicleMovementComponent->EngineSetup.EngineRevDownRate = 600.0f;			// 엔진 감속 속도

	// Set up the transmission
	VehicleMovementComponent->TransmissionSetup.bUseAutomaticGears = true;		// 자동 변속
	VehicleMovementComponent->TransmissionSetup.bUseAutoReverse = true;			// 자동 후진
	VehicleMovementComponent->TransmissionSetup.FinalRatio = 2.81f;				// 최종 감속비
	VehicleMovementComponent->TransmissionSetup.ChangeUpRPM = 6000.0f;			// 기어 변경 시점 (올림)
	VehicleMovementComponent->TransmissionSetup.ChangeDownRPM = 2000.0f;		// 기어 변경 시점 (내림)
	VehicleMovementComponent->TransmissionSetup.GearChangeTime = 0.2f;			// 기어 변경 시간
	VehicleMovementComponent->TransmissionSetup.TransmissionEfficiency = 0.9f;	// 동력 전달 효율

	// 기어 단 세팅
	// 바퀴 1회 회전 당 엔진 회전 수
	VehicleMovementComponent->TransmissionSetup.ForwardGearRatios.SetNum(5);
	VehicleMovementComponent->TransmissionSetup.ForwardGearRatios[0] = 4.25f;
	VehicleMovementComponent->TransmissionSetup.ForwardGearRatios[1] = 2.52f;
	VehicleMovementComponent->TransmissionSetup.ForwardGearRatios[2] = 1.66f;
	VehicleMovementComponent->TransmissionSetup.ForwardGearRatios[3] = 1.22f;
	VehicleMovementComponent->TransmissionSetup.ForwardGearRatios[4] = 1.0f;

	// 후진 기어 단 세팅
	VehicleMovementComponent->TransmissionSetup.ReverseGearRatios.SetNum(1);
	VehicleMovementComponent->TransmissionSetup.ReverseGearRatios[0] = 4.04f;

	// Set up the steering
	// 아커만 방식: 코너링 방향의 바퀴를 더 많이 꺾음
	VehicleMovementComponent->SteeringSetup.SteeringType = ESteeringType::Ackermann;
	VehicleMovementComponent->SteeringSetup.AngleRatio = 0.7f;	// 핸들링 방식 적용 비율
}
