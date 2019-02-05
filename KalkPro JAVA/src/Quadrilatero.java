import java.util.ArrayList;
import static java.lang.Math.sqrt;

public class Quadrilatero extends Poligono{

    public Quadrilatero(Punto a, Punto b, Punto c, Punto d) {
        super(new ArrayList<Punto>());
        pushVertice(a);
        pushVertice(b);
        pushVertice(c);
        pushVertice(d);
    }
    
    public double getArea() {
        ArrayList<Double> l = getLati();
        double diag1 = Punto.distanzaDuePunti((getVertice(0)),(getVertice(2)));
        double diag2 = Punto.distanzaDuePunti((getVertice(0)),(getVertice(2)));
        double diag = Math.min(diag1, diag2);
        if(diag1 <= diag2) {
            double semiP1 = (l.get(0)+l.get(1)+diag)/2;
            double area1 = sqrt(semiP1 * (semiP1-l.get(0)) * (semiP1-l.get(1)) * (semiP1-diag));
            double semiP2 = (diag+l.get(2)+l.get(3)/2);
            double area2 = sqrt(semiP2 * (semiP2-diag) * (semiP2-l.get(2)) * (semiP2-l.get(3)));
            return area1+area2;
        }
        else {
            double semiP1 = (l.get(0)+l.get(3)+diag)/2;
            double area1 = sqrt(semiP1 * (semiP1-l.get(0)) * (semiP1-l.get(3)) * (semiP1-diag));
            double semiP2 = (diag+l.get(1)+l.get(2)/2);
            double area2 = sqrt(semiP2 * (semiP2-diag) * (semiP2-l.get(2)) * (semiP2-l.get(3)));
            return area1+area2;
        }
    }

}
