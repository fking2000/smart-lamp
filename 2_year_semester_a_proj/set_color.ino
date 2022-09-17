
void color_converter (String hexValue)
{
    String hexstring = hexValue;
    long number = (long) strtol( &hexstring[1], NULL, 16);
    int r = number >> 16;
    int g = number >> 8 & 0xFF;
    int b = number & 0xFF;
    
  analogWrite(red,r );
  analogWrite(green,g );
  analogWrite(blue,b );
}
