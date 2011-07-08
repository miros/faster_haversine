#include <ruby.h>
#include <math.h>

static double haversine_distance(double lat1, double lng1, double lat2, double lng2);
static VALUE rb_haversine_distance(VALUE self, VALUE lat1, VALUE lng1, VALUE lat2, VALUE lng2);

void Init_faster_haversine()
{
  VALUE module = rb_define_module("FasterHaversine");
  rb_define_singleton_method(module, "haversine_distance", rb_haversine_distance, 4);
}

static VALUE rb_haversine_distance(VALUE self, VALUE lat1, VALUE lng1, VALUE lat2, VALUE lng2)
{
    double distance = haversine_distance(NUM2DBL(lat1), NUM2DBL(lng1), NUM2DBL(lat2), NUM2DBL(lng2));
	return rb_float_new(distance);
}

static const double EARTH_RADIUS = 6372.797560856; // Kilometers
static const double DEG_TO_RAD = M_PI / 180.0;

static double haversine_distance(double lat1, double lng1, double lat2, double lng2)
{
    double d_lng = (lng2 - lng1) * DEG_TO_RAD;
    double d_lat = (lat2 - lat1) * DEG_TO_RAD;
    double lat1_rad = lat1 * DEG_TO_RAD;
    double lat2_rad = lat2 * DEG_TO_RAD;
    double a =  pow(sin(d_lat * 0.5), 2) + cos(lat1_rad) * cos(lat2_rad) * pow(sin(d_lng * 0.5), 2);
    double c = 2.0 * atan2(sqrt(a), sqrt(1 - a));
    return EARTH_RADIUS * c;
}