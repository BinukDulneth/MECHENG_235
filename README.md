# ***MECHENG 235 PROJECT***'

###  *Both Balls were successfully delivered in 9.6 Seconds.*

#### Timeline of Testing & Optimization under the folder "src".
--------------------------------------------------------------------------------------------------------------
Functions : 
    
    Startup() : 
        The Safety Alarm which beeps to indicate the start of the operation. 
    
    Gaurdrail_Deply():
        Runs both the servos to lower the gaurdrail
    
    
    DettachServos():
        Dettaching the servos present in the Hands/Claws. Safety. 
    
    
    ShoulderBack(char Arm, byte Power):
        INPUT : 'S' : Short Arm         'L' : Long Arm  , Power value : 0(Turned Off) - 255(Max Speed)
        Base joint going down (away from the platform, towards the ball)
    
    ElbowBack(char Arm): 
        INPUT : 'S' : Short Arm       'L' : Long Arm
        Elbow Joint turning away from platform towards the ball. 
    
    ShoulderUp(char Arm): 
        INPUT : 'S' : Short Arm       'L' : Long Arm
        Base Joint turning up from balls towards the platform. 
    
    ElbowUp(char Arm): 
        INPUT : 'S' : Short Arm       'L' : Long Arm
        Elbow joint turning away from ball towards the platform. 
    
    ElbowStop(char Arm): 
        INPUT : 'S' : Short Arm       'L' : Long Arm
        Prevent the elbow joint from stalling. 
    
    
    ShoulderStop(char Arm): 
        INPUT : 'S' : Short Arm       'L' : Long Arm
        Prevent the shoulder joint from stalling. 
    
    
    
    FirstBlock():
        *After Gaurd rails being released. 
        Overview  :  
        1) Long Arm Grabs ball 
        2) Short Arm grabs ball 
        
        *Initially Claws are both open with the Long Arm's Claw on top of the Short Arm's Claw.
        *Long Arm grabs the ball elavated while the short arm grabs the ball on the stage.  
        Stepwise: 
            1) Long Arm Elbow goes Back 
            2) Long Arm Shoulder goes Back 
            3) Claw closes grabbing the ball. 
            4) Short Arm Elbow goes Back. 
            5) Short Arm Shoulder goes back. 
            6) Claw closes grabbing the ball. 
    
    SecondBlock(): 
        Overview : 
        1) Long Arm delivers the ball 
        2) Short Armrm delivers the ball 
        Stepwise : 
            1) Long Arm's shoulder goes up. 
            2) Long Arm's elbow goes up. 
            3) Opens claw dropping the ball on to the platform. 
            4) Long Arm's Elbow goes back. 
            5) Short Arm's Elbow goes up. 
            6) Short Arm's Shoulder goes up. 
            7) Opens claw dropping the ball on to the platform. 
            