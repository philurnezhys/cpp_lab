#include <iostream>

using namespace std;

class safe_long_long_t {
private:
    long long val;
public:
    explicit safe_long_long_t(long long x) {
        val = x;
    }

    safe_long_long_t operator = (const safe_long_long_t & a) {
        val = a.val;
        return *this;
    }

    safe_long_long_t & operator += (const safe_long_long_t & a) {
        val += a.val;
        return *this;
    }

    safe_long_long_t & operator -= (const safe_long_long_t & a) {
        val -= a.val;
        return *this;
    }

    safe_long_long_t & operator *= (const safe_long_long_t & a) {
        val *= a.val;
        return *this;
    }

    safe_long_long_t & operator /= (const safe_long_long_t & a) {
        val /= a.val;
        return *this;
    }

    safe_long_long_t & operator %= (const safe_long_long_t & a) {
        val %= a.val;
        return *this;
    }

    safe_long_long_t & operator++() {
        val++;
        return *this;
    }

    safe_long_long_t operator++(int i) {
        safe_long_long_t oldVal = * this;
        ++ * this;
        return oldVal;
    }

    safe_long_long_t & operator--() {
        --val;
        return *this;
    }

    safe_long_long_t operator--(int i) {
        safe_long_long_t oldVal = * this;
        -- * this;
        return oldVal;
    }

    friend ostream & operator << (ostream & out,
                                  const safe_long_long_t & a) {
        out << a.val;
        return out;
    };

    friend istream & operator >> (istream & in , safe_long_long_t & a) {
        in >> a.val;
        return in;
    };

    friend bool operator == (const safe_long_long_t & a,
                             const safe_long_long_t & b);
    friend bool operator > (const safe_long_long_t & a,
                            const safe_long_long_t & b);
    friend bool operator < (const safe_long_long_t & a,
                            const safe_long_long_t & b);
    friend bool operator >= (const safe_long_long_t & a,
                             const safe_long_long_t & b);
    friend bool operator <= (const safe_long_long_t & a,
                             const safe_long_long_t & b);
};

safe_long_long_t operator + (safe_long_long_t a,
                             const safe_long_long_t & b) {
    return (a += b);
}

safe_long_long_t operator - (safe_long_long_t a,
                             const safe_long_long_t & b) {
    return (a -= b);
}

safe_long_long_t operator * (safe_long_long_t a,
                             const safe_long_long_t & b) {
    return (a *= b);
}

safe_long_long_t operator / (safe_long_long_t a,
                             const safe_long_long_t & b) {
    return (a /= b);
}

safe_long_long_t operator % (safe_long_long_t a,
                             const safe_long_long_t & b) {
    return (a %= b);
}

bool operator == (const safe_long_long_t & a,
                  const safe_long_long_t & b) {
    return (a.val == b.val);
}

bool operator != (const safe_long_long_t & a,
                  const safe_long_long_t & b) {
    return !(a == b);
}

bool operator > (const safe_long_long_t & a,
                 const safe_long_long_t & b) {
    return (a.val > b.val);
}

bool operator < (const safe_long_long_t & a,
                 const safe_long_long_t & b) {
    return !((a > b) || (a == b));
}

bool operator >= (const safe_long_long_t & a,
                  const safe_long_long_t & b) {
    return ((a > b) || (a == b));
}

bool operator <= (const safe_long_long_t & a,
                  const safe_long_long_t & b) {
    return !(a > b);
}

class safe_c_array_t: public error_code {
private: int size;
    int * arr;
public: explicit safe_c_array_t(int n) {
        size = n;
        arr = new int[size];
    }

    safe_c_array_t & operator = (const safe_c_array_t & arr2) {
        if (this != & arr2) {
            delete[] arr;
            size = arr2.size;
            arr = new int[size];
            for (int i = 0; i < size; i++) {
                arr[i] = arr2.arr[i];
            }
        }
        return *this;
    }

    safe_c_array_t(const safe_c_array_t & origin) {
        size = origin.size;
        arr = new int[size];
        for (int i = 0; i < size; i++) {
            arr[i] = origin.arr[i];
        }
    }

    void fill() {
        for (int i = 0; i < size; i++) {
            arr[i] = i;
        }
    }

    int & operator[](int k) {
        return arr[k];
    }

    ~safe_c_array_t() {
        delete[] arr;
    }

};

int main() {
    safe_long_long_t a(2);
    safe_long_long_t b(4);
    cout << a + b << endl;
    cout << a * b << endl;
    cout << a / b << endl;
    cout << a - b << endl;
    cout << a-- << ' ' << --a << endl << endl;

    safe_c_array_t arr = safe_c_array_t(9);
    safe_c_array_t arr_copy = safe_c_array_t(arr);
    arr.fill();
    arr_copy.fill();
    safe_c_array_t arr2 = arr_copy;
    cout << arr[3] << endl;
    cout << arr_copy[4] << endl;
    cout << arr2[8] << endl;

    return 0;

}