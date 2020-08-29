// When to use weak_ptr ?
// When you do want to refer to your object from multiple places – for those references
// for which it’s ok to ignore and deallocate(so they’ll just note the object is gone
// when you try to dereference).