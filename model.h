#ifndef model_h
#define model_h
class Model{
public:
    void read_in_data();
    void write_out_data();
    void add_item(Item* item);
private:
    Data_library _data_library;
};
#endif /* model_h */
