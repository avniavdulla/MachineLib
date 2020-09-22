#include "pch.h"
#include "MachineFactory2.h"

#include "MachineActual.h"
#include "Shape.h"
#include "Motor.h"
#include "Pulley.h"
#include "SnowBlower.h"

using namespace std;

/**
 * Constructor
 */
CMachineFactory2::CMachineFactory2()
{
}


/**
 * Destructor
 */
CMachineFactory2::~CMachineFactory2()
{
}


/**
 * Create a machine object
 * \returns Object of type CMachine
 */
std::shared_ptr<CMachineActual> CMachineFactory2::CreateMachine()
{
    auto machine = make_shared<CMachineActual>();
    
    /// Top of the trailer in pixels
    int TopOfTrailer = 82;

    /// Left post x position 
    int LeftPostX = -130;

    /// Right post x position 
    int RightPostX = 130;
    /// Blower position 
    int BlowerPositionX = 70;
    /// Blower position 
    int BlowerPositionY= -350;

    
    //
    // Base 
    //
    auto base = make_shared<CShape>();
    int wid = 400;
    base->Rectangle(-wid / 2, 0, wid, 82);
    base->SetImage(L"images/trailer.png");
    machine->AddComponent(base);

    //
    // The motor  
    //
    auto motor = make_shared<CMotor>();
    wid = 70;
    motor->Rectangle(-wid / 2, 0, wid, 70);
    motor->SetImage(L"images/motor3.png");
    motor->SetCenter(Gdiplus::Point(0, -80));
    machine->AddComponent(motor);

    //
    // Right post
    //
    auto rightPost = make_shared<CShape>();
    wid = 20;
    rightPost->Rectangle(-wid / 2, 0, wid, 300);
    rightPost->SetImage(L"images/rust.png");
    rightPost->SetCenter(Gdiplus::Point(RightPostX, -80));
    machine->AddComponent(rightPost);

    //
    // Snow Blower driven by pulley6
    //
    auto blower = make_shared<CSnowBlower>(0.25);
    wid = 120;
    blower->Rectangle(-wid / 2, 0, wid, 160);
    blower->SetImage(L"images/blowerR.png");
    blower->SetCenter(Gdiplus::Point(BlowerPositionX, BlowerPositionY));
    machine->AddComponent(blower);

    //
    // Left post
    //
    auto leftPost = make_shared<CShape>();
    wid = 20;
    leftPost->Rectangle(-wid / 2, 0, wid, 90);
    leftPost->SetImage(L"images/rust.png");
    leftPost->SetCenter(Gdiplus::Point(LeftPostX, -80));
    machine->AddComponent(leftPost);

    //
    // Middle post
    //
    auto middlePost = make_shared<CShape>();
    wid = 150;
    middlePost->Rectangle(-wid / 2, 0, wid, 20);
    middlePost->SetImage(L"images/rust.png");
    middlePost->SetCenter(Gdiplus::Point(RightPostX / 2, -260));
    machine->AddComponent(middlePost);


    //
    // The pulley driven by the motor
    // Radius=15pixels
    //
    auto pulley1 = make_shared<CPulley>(15);
    pulley1->Circle(15);
    pulley1->SetImage(L"images/pulley.png");
    pulley1->SetCenter(Gdiplus::Point(0, -115));
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
    pulley2->SetCenter(Gdiplus::Point(LeftPostX, -160));
    pulley2->SetPhase(.01); // Rotate a lil bit 
    machine->AddComponent(pulley2);

    // Pulley 1 drives 2 using a belt 
    pulley1->Drive(pulley2);

    //
    // Pulley 3 driven by pulley 2
    // 
    auto pulley3 = make_shared<CPulley>(20);
    pulley3->Circle(20);
    pulley3->SetImage(L"images/pulley.png");
    pulley3->SetCenter(Gdiplus::Point(LeftPostX, -160));
    pulley3->SetPhase(.01); // Rotate a lil bit 
    machine->AddComponent(pulley3);

    // Pulley 2 directly drives 3
    pulley2->GetSource()->AddSink(*pulley3->GetSink());

    //
    // Pulley 4 driven by pulley 3 
    //
    auto pulley4 = make_shared<CPulley>(40);
    pulley4->Circle(40);
    pulley4->SetImage(L"images/pulley2.png");
    pulley4->SetCenter(Gdiplus::Point(0, -270));
    pulley4->SetPhase(.01); // Rotate a lil bit 
    machine->AddComponent(pulley4);

    // Pulley 3 drives 4 using a belt 
    pulley3->Drive(pulley4);

    //
    // Pulley 5 driven by pulley 4 
    //
    auto pulley5 = make_shared<CPulley>(20);
    pulley5->Circle(20);
    pulley5->SetImage(L"images/pulley.png");
    pulley5->SetCenter(Gdiplus::Point(0, -270));
    pulley5->SetPhase(.01); // Rotate a lil bit 
    machine->AddComponent(pulley5);

    // Pulley 4 directly drives 5
    pulley4->GetSource()->AddSink(*pulley5->GetSink());

    //
    // Pulley 6 driven by pulley 5 
    //
    auto pulley6 = make_shared<CPulley>(20);
    pulley6->Circle(20);
    pulley6->SetImage(L"images/pulley.png");
    pulley6->SetCenter(Gdiplus::Point(0, -270));
    pulley6->SetPhase(.01); // Rotate a lil bit 
    machine->AddComponent(pulley6);

    // Pulley 5 directly drives 6
    pulley5->GetSource()->AddSink(*pulley6->GetSink());

    
    
    //
    // Pulley 7 driven by pulley 6 
    //
    auto pulley7 = make_shared<CPulley>(45);
    pulley7->Circle(45);
    pulley7->SetImage(L"images/pulley2.png");
    pulley7->SetCenter(Gdiplus::Point(RightPostX, BlowerPositionY));
    pulley7->SetPhase(.01); // Rotate a lil bit 
    machine->AddComponent(pulley7);

    pulley6->Drive(pulley7);

    // pulley that drives the snow blower 
    pulley7->GetSource()->AddSink(*blower->GetSink());



    return machine;

}