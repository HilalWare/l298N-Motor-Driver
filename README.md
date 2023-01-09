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

Umarım bu bilgi sizin için faydalı olmuştur. Eğer daha fazla sorunuz olurs
