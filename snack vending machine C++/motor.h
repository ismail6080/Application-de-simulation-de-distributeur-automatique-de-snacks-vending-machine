#ifndef MOTOR_H
#define MOTOR_H
class Motor {
protected:
int id;
public :
 Motor(int ID);
 int getId();
 void Trigger();
};

#endif // MOTOR_H
