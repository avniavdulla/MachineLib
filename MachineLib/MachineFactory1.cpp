#include "pch.h"
#include "MachineFactory1.h"

#include "MachineActual.h"
#include "Shape.h"
#include "Motor.h"
#include "Pulley.h"
#include "SnowBlower.h"

using namespace std;

/**
 * Constructor
 */
CMachineFactory1::CMachineFactory1()
{
}


/**
 * Destructor
 */
CMachineFactory1::~CMachineFactory1()
{
}


/**
 * Create a machine object
 * \returns Object of type CMachine
 */
std::shared_ptr<CMachineActual> CMachineFactory1::CreateMachine()
{
    auto machine = make_shared<CMachineActual>();
    
    //
    // The base
    //
    auto base = make_shared<CShape>();
    int wid = 325;
    base->Rectangle(-wid / 2, 0, wid, 40);
    base->SetImage(L"images/base.png");
    machine->AddComponent(base);

    //
    // The motor  
    //
    auto motor = make_shared<CMotor>();
    wid = 70;
    motor->Rectangle(-wid / 2, 0, wid, 70);
    motor->SetImage(L"images/motor3.png");
    motor->SetCenter(Gdiplus::Point(0, -35));
    machine->AddComponent(motor);

    //
    // Snow Blower driven by pulley2
    //
    auto blower = make_shared<CSnowBlower>(-0.15);
    wid = 120;
    blower->Rectangle(-wid / 2, 0, wid, 160);
    blower->SetImage(L"images/blowerL.png");
    blower->SetCenter(Gdiplus::Point(-40, -75));
    machine->AddComponent(blower);

    //
    // Post to hold the first pulley
    // Must be added before the motor pulley so it draws behind the belt
    //
    auto post1 = make_shared<CShape>();
    wid = 20;
    post1->Rectangle(-wid / 2, 0, wid, 80);
    post1->SetCenter(Gdiplus::Point (-80, -40));
    machine->AddComponent(post1);


    //
    // Post to hold the second pulley
    // Must be added before the motor pulley so it draws behind the belt
    //
    auto post2 = make_shared<CShape>();
    wid = 20;
    post2->Rectangle(-wid / 2, 0, wid, 140);
    post2->SetCenter(Gdiplus::Point(100, -40));
    machine->AddComponent(post2);


    //
    // The pulley driven by the motor
    // Radius=15pixels
    //
    auto pulley1 = make_shared<CPulley>(15);
    pulley1->Circle(15);
    pulley1->SetImage(L"images/pulley.png");
    pulley1->SetCenter(Gdiplus::Point(0, -70));
    pulley1->SetPhase(0.1);	// Rotate it a little bit
    machine->AddComponent(pulley1);

    // connect motor to pulley 
    motor->GetSource()->AddSink(*pulley1->GetSink());


    //
    // Pulley 2 driven by pulley 1 
    //
    auto pulley2 = make_shared<CPulley>(40);
    pulley2->Circle(40);
    pulley2->SetImage(L"images/pulley.png");
    pulley2->SetCenter(Gdiplus::Point(-80, -115));
    pulley2->SetPhase(.01); // Rotate a lil bit 
    machine->AddComponent(pulley2);

    //pulley1->GetSource()->AddSink(*pulley2->GetSink());
    pulley1->Drive(pulley2);

    pulley1->GetSource()->AddSink(*blower->GetSink());

    //
    // Smaller pulley attached to pulley 2
    //
    auto smaller2 = make_shared<CPulley>(20);
    smaller2->Circle(20);
    smaller2->SetImage(L"images/pulley2.png");
    smaller2->SetCenter(Gdiplus::Point(-80, -115));
    smaller2->SetPhase(.01); // Rotate a lil bit 
    machine->AddComponent(smaller2);

    pulley2->GetSource()->AddSink(*smaller2->GetSink());
    pulley2->GetSource()->AddSink(*blower->GetSink());


    // 
    // Pulley driven by pulley 2 
    //
    auto pulley3 = make_shared<CPulley>(40);
    pulley3->Circle(40);
    pulley3->SetImage(L"images/pulley.png");
    pulley3->SetCenter(Gdiplus::Point(100, -170));
    pulley3->SetPhase(.01); // Rotate a lil bit 
    machine->AddComponent(pulley3);

    smaller2->Drive(pulley3);

    //
    // Flag
    // 
    auto flag = make_shared<CShape>();
    flag->AddPoint(-50, 0);
    flag->AddPoint(-50, -100);
    flag->AddPoint(5, -100);
    flag->AddPoint(5, 0);
    flag->SetImage(L"images/flag.png");
    flag->SetCenter(Gdiplus::Point(100, -170));
    machine->AddComponent(flag);

    pulley3->GetSource()->AddSink(*flag->GetSink());

    return machine;

}