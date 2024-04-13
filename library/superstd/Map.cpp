template <typename Key, typename Val> struct Map : std<Key, Val> {
    using std<Key, Val>::erase;

    void operator()(Key key, Val val) {
        if (!((*this)[key] += val))
            erase(key);
    }
};