template <typename Key, typename Val> struct Map : std::map<Key, Val> {
    using std::map<Key, Val>::erase;

    void operator()(Key key, Val val) {
        if (!((*this)[key] += val))
            erase(key);
    }
};