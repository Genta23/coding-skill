template<typename T> bool check(T s, T t, T s__, T t__){
    if(s < 0) return false;
    if(t < 0) return false;
    if(s >= s__) return false;
    if(t >= t__) return false;
    return true;
}
template<typename T> bool checker(T s, T t, T s__, T t__){ return ((s >= 0 && t >= 0 && s < s__ && t < t__) ? true : false); }