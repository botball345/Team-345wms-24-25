#include <kipr/wombat.h>
int right=0;
int left=3;
int main()
{


    //pom-poms
    enable_servos();
    motor(right,98);
    motor(left,86);
    msleep(1000);
    set_servo_position(1,819);
    set_servo_position(2,2002);
    msleep(500);
    motor(right,100);
    motor(left,83.5);
    msleep(3500);
    set_servo_position(1,2000);
    msleep(500);

    
    // bottles mission
    motor(right,98);
    motor(left,80.5);
    msleep(4100);
    //turn
    motor(left,81);
    motor(right,100);
    msleep(600);

    //driving towads untill hits the wall 
    while (digital(0)==0)
    {
        motor(right,100);
        motor(left,87);


    }
    //driving backwards until hits back wall
    ao();
    {
        while (digital(2)==0)
        {   
            motor(right,-100);
            motor(left,-87);
        }
        ao();
    }
    {
        //wait
        motor(right,0);
        motor(left,0);
        msleep(2000);
        //lower claw
        enable_servos();

        set_servo_position(2,1700);

        msleep(500);

        set_servo_position(1,1000);
        msleep(500);

        //drive straight
        motor(right,29);
        motor(left,25);
        msleep(4200);



        //wait
        motor(0,0);
        motor(3,0);
        msleep(2000);
        //close claw
        set_servo_position(1,2000);
        msleep(250);
        //wait
        motor(0,0);
        motor(3,0);
        msleep(2000);   

        //lift UP
        set_servo_position(2,1029);
        msleep(250);
        //back up against the wall
        while (digital(2)==0)
        {
            motor(right,-98);
            motor(left,-83.5);
        }
        ao();
    }
    //turn after hits wall
    {   
        motor(right,100);
        motor(left,0);
        msleep(2800);
        //lower claw to drop water bottles
        set_servo_position(2,1500);
        msleep(250);
        set_servo_position(2,1630);
        msleep(250);
        set_servo_position(1,1000);
        msleep(500);

        while (digital(2)==0)
        {
            motor(right,-82);
            motor(left,-100);



        }
    }
    {




    }

    return 0;
}



