#include <iostream>

using namespace std;

template<typename T>
class QwtSeriesData {
 public:
  QwtSeriesData(T val) : val_(val) {}
  virtual ~QwtSeriesData() = default;
  T GetData() const {
    return val_;
  }
 private:
  T val_;
};

class CurveData : public QwtSeriesData<int> {
 public:
  CurveData(int v) : QwtSeriesData<int>(v) {}
};

template<typename T>
class PointerHandle {
 public:
  PointerHandle(QwtSeriesData<T> *ptr) {
    d_series = ptr;
  }
  const QwtSeriesData<T> *data() const {
    return d_series;
  }
 private:
  QwtSeriesData<T> *d_series;
};

int main()
{
    CurveData data(5);
    CurveData *data_ptr = &data;
    PointerHandle<int> d_curve(data_ptr);
    QwtSeriesData<int> *temp_ptr = const_cast<QwtSeriesData<int>* >(
                                              d_curve.data());
    CurveData *curve = dynamic_cast<CurveData *>(temp_ptr);

    cout << curve->GetData() << endl;
    return 0;
}
