# l298N-Motor-Driver

L298N, bir DC motor sürücüsüdür ve iki DC motoru veya bir adet stepper motorun hızını ve yönünü kontrol etmek için kullanılır. Bu sürücü, bir microcontroller veya bir bilgisayar gibi bir cihazdan alınan giriş sinyallerine göre motorları çalıştırır.

L298N, bir DC motorun çalışmasını kontrol etmek için iki farklı giriş sinyali gerektirir:

Motorun hızını ayarlamak için PWM (Pulse Width Modulation) sinyali
Motorun yönünü ayarlamak için bir "sağ dönüş" sinyali ve bir "sol dönüş" sinyali
Aşağıda, L298N kullanılarak iki DC motorun kontrolünü sağlayan bir örnek kod bulabilirsiniz:

```c++
#include <L298N.h>

L298N motorDriver(ENA, IN1, IN2, ENB, IN3, IN4); // L298N sürücüsünü oluşturun

void setup() {
  // Motorların hızını ayarlamak için PWM pinlerine bağlayın
  motorDriver.setPWMpins(3, 11, 6, 5);
}

void loop() {
  // Motor A'yı %50 hızında sağa döndürün
  motorDriver.setSpeedA(50);
  motorDriver.runA(FORWARD);

  // Motor B'yi %50 hızında sola döndürün
  motorDriver.setSpeedB(50);
  motorDriver.runB(BACKWARD);

  delay(2000); // 2 saniye bekleyin

  // Motor A'yı durdurun
  motorDriver.runA(RELEASE);

  // Motor B'yi durdurun
  motorDriver.runB(RELEASE);

  delay(1000); // 1 saniye bekleyin
}
```


Bu örnek kod, L298N sürücüsünün setPWMpins() fonksiyonu ile PWM pinlerini ayarlar ve setSpeedA() ve setSpeedB() fonksiyonları ile motorların hızını ayarlar. Daha sonra, runA() ve runB() fonksiyonları ile motorların yönünü belirler ve FORWARD, BACKWARD veya RELEASE değerlerini kullanarak motorları çalıştırır veya durdurur.



<h1> English </h1>
The L298N is a DC motor driver that is used to control the speed and direction of two DC motors or one stepper motor. This driver operates the motors based on input signals received from a device such as a microcontroller or a computer.

To control the operation of a DC motor, the L298N requires two different input signals:

A PWM (Pulse Width Modulation) signal to adjust the speed of the motor
A "right turn" signal and a "left turn" signal to adjust the direction of the motor
Below is an example code that demonstrates how to control two DC motors using the L298N:
```c++
#include <L298N.h>

L298N motorDriver(ENA, IN1, IN2, ENB, IN3, IN4); // Create L298N driver

void setup() {
  // Connect PWM pins to adjust motor speed
  motorDriver.setPWMpins(3, 11, 6, 5);
}

void loop() {
  // Turn motor A right at 50% speed
  motorDriver.setSpeedA(50);
  motorDriver.runA(FORWARD);

  // Turn motor B left at 50% speed
  motorDriver.setSpeedB(50);
  motorDriver.runB(BACKWARD);

  delay(2000); // Wait 2 seconds

  // Stop motor A
  motorDriver.runA(RELEASE);

  // Stop motor B
  motorDriver.runB(RELEASE);

  delay(1000); // Wait 1 second
}
```
This example code sets the PWM pins using the setPWMpins() function and adjusts the speed of the motors using the setSpeedA() and setSpeedB() functions. Then, it determines the direction of the motors using the runA() and runB() functions and operates or stops the motors using the FORWARD, BACKWARD, or RELEASE values.
