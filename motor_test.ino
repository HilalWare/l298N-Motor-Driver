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
