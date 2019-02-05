import java.util.ArrayList;

abstract class Poligono implements Forma{
    private ArrayList<Punto> vertici;

    public Poligono(ArrayList<Punto> l) {
        vertici = l;
    }

    public ArrayList<Double> getLati() {
        ArrayList<Double> t = new ArrayList<Double>();
        for(int i = 0; i <vertici.size()-1; ++i) {
            t.add(Punto.distanzaDuePunti(vertici.get(i),vertici.get(i+1)));
        }
        t.add(Punto.distanzaDuePunti(vertici.get(0),vertici.get(vertici.size()-1)));
        return t;
    }

    public double getPerimetro() {
        double perim = 0;
        ArrayList<Double> lati = getLati();
        for(int i = 0; i < vertici.size(); ++i) {
            perim += lati.get(i);
        }
        return perim;
    }

    public int contaVertici() {
        int nVertici = 0;
        for(int i = 0; i < vertici.size(); ++i) {
            nVertici++;
        }
        return nVertici;
    }

    public Punto getBaricentro() {
        int nVertici = contaVertici();
        double numerX = 0;
        double numerY = 0;
        for(int i = 0; i < nVertici; ++i) {
            numerX += vertici.get(i).getX();
            numerY += vertici.get(i).getY();
        }
        return new Punto(numerX / nVertici, numerY / nVertici);
    }

    public double getLato(int i) {
        return getLati().get(i);
    }

    public Punto getVertice(int i) {
        return vertici.get(i);
    }

    public void setVertice(int i, Punto p) {
        vertici.get(i).setX(p.getX());
        vertici.get(i).setY(p.getY());
    }

    protected void pushVertice(Punto p) {
        vertici.add(p);
    }
}
