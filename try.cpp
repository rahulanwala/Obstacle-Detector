// C++ code

long duration = 0;
int distance = 0;

void setup()
{
    pinMode(6, INPUT);
    pinMode(2, OUTPUT);
    pinMode(9, OUTPUT);
    Serial.begin(9600);
    Serial.println("Hello World");
    Serial.println();
}

void loop()
{
    if (digitalRead(6) == HIGH)
    {
        distance = 0;
        duration = 0;
        digitalWrite(2, LOW);
        delay(0.002); // Wait for 0.002 millisecond(s)
        digitalWrite(2, HIGH);
        delay(0.01); // Wait for 0.01 millisecond(s)
        digitalWrite(2, LOW);
        duration = pulseIn(3, HIGH);
        distance = duration * 0.034 / 2;
        Serial.print("Distance: ");
        Serial.print(distance);
        Serial.println(" cm");

        if (distance > 100)
        {
        }
        else if (distance <= 100 && distance > 60)
        {
            tone(9, 100);
            delay(1000);
            noTone(9);
        }
        else if (distance <= 60 && distance > 25)
        {
            tone(9, 311);
            delay(500);
            noTone(9);
        }
        else
        {
            tone(9, 500);
            delay(10);
            noTone(9);
        }
    }
}
}