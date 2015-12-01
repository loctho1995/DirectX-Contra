#pragma once
#include "Sprite.h"
//1 Joint la 1 khop xuong

class Boss2FinalJoint : public Sprite
{
public:
    enum MoveAroundDirection
    {
        Positive, //chieu duong - chieu kim dong ho
        Negative, //chieu am
        Unknow //default
    };

    Boss2FinalJoint(float x, float y);
    Boss2FinalJoint();
    ~Boss2FinalJoint();

    virtual void defaultSetting();

    virtual void update();
    virtual void draw(Camera *cam);

    virtual void setPosition(float x, float y);

    virtual D3DXVECTOR2 getPosition();
    //di chuyen toi vi tri x,y sau [frames] Frame - chuyen dong deu
    //virtual void moveTo(float x, float y, int frames, int delayFrame = 0);

    //di chuyen theo van toc vx, vy trong vong frames Frame
    virtual void moveBy(float x, float y, int frames, int delayFrame = 0);

    //di chuyen vong tron quanh toa do x,y ban kinh radius voi van toc speed (Degree / frame) - chuyen dong deu
    virtual void moveAround(float x, float y, float radius, int frames, float speed, MoveAroundDirection direction, float accelemetor = 0, int delayFrame = 0);

    virtual void moveFollow(Boss2FinalJoint *joint, bool isMoveFollowWithAccelemetor = true);

    virtual void setMoveAroundSpeed(float speed);

    virtual void setMoveAroundRadius(float radius);

    virtual void reverseMoveAroundDirection();

    virtual void setMoveAroundDelay(int frame);

    virtual float getAngleSpeed();

    virtual void stopMoveFollow();

    virtual int getMoveAroundCurrFrame();

    virtual D3DXVECTOR2 getCurrentMoveDirection();

    virtual void stopMoveAround();

    virtual void alignDistance(Boss2FinalJoint* joint2); // lam cho joint1 luon cach joint2 1 khoang = tong ban kinh 2 thang luon co dinh

    bool    isMoveAround, 
            isMoveTo,
            isMoveBy,
            isMoveByVelocity,
            isMoveFollow;

    float distanceMoved;
    float angleMoved;
    float moveAroundSpeed; // (Degree / frame)
    MoveAroundDirection moveAroundDirection;

protected:
    void updateMoveBy(float oldx, float oldy);
    void updateMoveFollow();
    void updateMoveTo(float oldx, float oldy);
    void updateMoveAround();    

    float   moveAroundX,
            moveAroundY,
            moveAroundRadius,
            moveAroundDelay,
            moveAroundFrame,
            moveAroundAccelemetor,
            moveToX,
            moveToY,
            moveToFrame,
            moveToCurrFrame,
            moveByCurrFrame,
            moveByFrame,
            moveByDelay;

    int moveToDelay, moveAroundCurrFrame;

    D3DXVECTOR2 currMoveDirection;

    Boss2FinalJoint *jointFollow;

    bool isMoveAroundAcclemetor, allowMoveReverse, isJointFollowStoped, isMoveFollowFirstTime, isMoveFollowWithAccelemetor;
};

