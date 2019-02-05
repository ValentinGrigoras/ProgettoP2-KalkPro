public class Circonferenza implements Forma{
    private Punto centro;
    private double raggio;

    public Circonferenza(Punto p, int i) {
        centro = p;
        raggio = i;
    }

    public double getArea() {
        double a = raggio * raggio * Math.PI;
        return a;
    }

    public double getPerimetro() {
        double p = 2 * raggio * Math.PI;
        return p;
    }

    public Punto getBaricentro() {
        return centro;
    }

    public double getRaggio() {
        return raggio;
    }
    
    public void setRaggio(double d) {
    	raggio = d;
    	
    }
 }
