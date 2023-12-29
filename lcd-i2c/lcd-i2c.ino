#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Inicialização da tela LCD
// parâmetros: endereço I2C, número de colunas e número de linhas da tela
// nota: acompanhe o monitor serial para ver a porta I2C
// nota2: busquei bons modos de não precisar setar o valor do endereço
// manualmente, mas isso obrigaria a declarar a tela lcd duas vezes ou,
// então, declarar no loop (o que parece péssimo).
#define lcd_n_col 16      // define o numero de colunas do display utilizado
#define lcd_n_lin 2       // define o numero de linhas do display utilizado
#define endereco_i2c 0x27 // endereço I2c (veja função obterEnderecoI2C)
LiquidCrystal_I2C lcd(endereco_i2c, lcd_n_col, lcd_n_lin);

int obterEnderecoI2C()
{
  Wire.begin();
  byte erro, endereco;
  int n_dispositivos = 0;
  for (endereco = 1; endereco < 127; endereco++)
  {
    Wire.beginTransmission(endereco);
    erro = Wire.endTransmission();
    if (erro == 0)
    {
      n_dispositivos++;
      return endereco;
    }
    else if (erro == 4)
    {
      Serial.println("Erro ao obter informação da conexão.");
      Serial.println("A rotina será interrompida.");
      exit(1);
    }
  }

  if (n_dispositivos == 0)
  {
    Serial.println("Nenhum dispositivo I2C encontrado.");
    Serial.println("A rotina será interrompida.");
    exit(1);
  }
}

void setup()
{
  Serial.begin(9600);
  while (!Serial)
    ;

  // #################################################################################
  // Identificação da porta I2C
  // #################################################################################
  Serial.println("I2C Scanner");
  int endereco = obterEnderecoI2C();
  Serial.print("Endereço I2C (HEX): 0x");
  Serial.println(endereco, HEX);

  // #################################################################################
  // Uso da tela
  // #################################################################################
  lcd.init();                 // inicia a comunicação com o display já conectado
  lcd.backlight();            // liga a luz do display
  lcd.clear();                // limpa a tela do display
  lcd.setCursor(0, 0);        // seta a posição inicial do cursor antes de desenhar
  lcd.print("LCD operando!"); // desenha os caractetes (não renderiza acentos)
  delay(1000);
}

void loop()
{
  lcd.clear();
  int linha, coluna;
  for (linha = 0; linha < 2; linha++)
  {
    for (coluna = 0; coluna < 16; coluna++)
    {
      lcd.setCursor(coluna, linha);
      lcd.print(">>>");
      delay(100);
      lcd.clear();
    }
  }

  lcd.setCursor(0, 0);
  lcd.print("_(o.o)_ ola");
  delay(1000);
}
