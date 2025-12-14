#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET -1
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

#define POT_PIN A0
#define BIRD_X 10
#define BIRD_SIZE 4
#define WALL_WIDTH 8
#define WALL_GAP 20   
#define NUM_WALLS 3   

struct Wall {
  int x;
  int gapY;
};

Wall walls[NUM_WALLS];
int wallSpacing = 50; 
int score = 0;
int gameOver = 0;
int speed = 2; 

void resetGame() {
  score = 0;
  gameOver = 0;
  speed = 2;
  for (int i = 0; i < NUM_WALLS; i++) {
    walls[i].x = SCREEN_WIDTH + i * wallSpacing;
    walls[i].gapY = random(5, SCREEN_HEIGHT - WALL_GAP - 5);
  }
}

void setup() {
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.clearDisplay();
  randomSeed(analogRead(A1));
  resetGame();
}

void loop() {
  if (!gameOver) {
    
    int potVal = analogRead(POT_PIN);
    int birdY = map(potVal, 0, 1023, 0, SCREEN_HEIGHT - BIRD_SIZE);

    
    for (int i = 0; i < NUM_WALLS; i++) {
      walls[i].x -= speed;

      if (walls[i].x < -WALL_WIDTH) {
        walls[i].x = SCREEN_WIDTH;
        walls[i].gapY = random(5, SCREEN_HEIGHT - WALL_GAP - 5);
        score++; 
        if (score % 5 == 0 && speed < 6) speed++; 
      }
    }

   
    display.clearDisplay();

    
    display.fillRect(BIRD_X, birdY, BIRD_SIZE, BIRD_SIZE, SSD1306_WHITE);

 
    for (int i = 0; i < NUM_WALLS; i++) {
      display.fillRect(walls[i].x, 0, WALL_WIDTH, walls[i].gapY, SSD1306_WHITE);
      display.fillRect(walls[i].x, walls[i].gapY + WALL_GAP, WALL_WIDTH,
                       SCREEN_HEIGHT - (walls[i].gapY + WALL_GAP),
                       SSD1306_WHITE);

      if (BIRD_X + BIRD_SIZE > walls[i].x && BIRD_X < walls[i].x + WALL_WIDTH) {
        if (birdY < walls[i].gapY || birdY + BIRD_SIZE > walls[i].gapY + WALL_GAP) {
          gameOver = 1;
        }
      }
    }

 
    display.setTextSize(1);
    display.setTextColor(SSD1306_WHITE);
    display.setCursor(0, 0);
    display.print("Score: ");
    display.print(score);

    display.display();
    delay(40);

  } else {
    // GAME OVER Page
    display.clearDisplay();
    display.setTextSize(2);
    display.setTextColor(SSD1306_WHITE);
    display.setCursor(20, 20);
    display.print("GAME OVER");
    display.setTextSize(1);
    display.setCursor(40, 50);
    display.print("Score: ");
    display.print(score);
    display.display();
    delay(2000);
    resetGame(); // auto reset
  }
}
