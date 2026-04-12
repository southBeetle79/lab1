class Barrel{
private:
    double volume;
    double alcohol_content;
public:
    Barrel(double start_vol, double concentration);

    double get_concentration_percent() const;

    void pour_from(Barrel& source, double amount);

    void add_liquid(double total_amt, double alcohol_amt);
    double extract_liquid(double amount);
};