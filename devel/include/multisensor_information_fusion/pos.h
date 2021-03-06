// Generated by gencpp from file multisensor_information_fusion/pos.msg
// DO NOT EDIT!


#ifndef MULTISENSOR_INFORMATION_FUSION_MESSAGE_POS_H
#define MULTISENSOR_INFORMATION_FUSION_MESSAGE_POS_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace multisensor_information_fusion
{
template <class ContainerAllocator>
struct pos_
{
  typedef pos_<ContainerAllocator> Type;

  pos_()
    : x(0.0)
    , y(0.0)
    , psi(0.0)
    , dx(0.0)
    , dpsi(0.0)  {
    }
  pos_(const ContainerAllocator& _alloc)
    : x(0.0)
    , y(0.0)
    , psi(0.0)
    , dx(0.0)
    , dpsi(0.0)  {
  (void)_alloc;
    }



   typedef float _x_type;
  _x_type x;

   typedef float _y_type;
  _y_type y;

   typedef float _psi_type;
  _psi_type psi;

   typedef float _dx_type;
  _dx_type dx;

   typedef float _dpsi_type;
  _dpsi_type dpsi;




  typedef boost::shared_ptr< ::multisensor_information_fusion::pos_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::multisensor_information_fusion::pos_<ContainerAllocator> const> ConstPtr;

}; // struct pos_

typedef ::multisensor_information_fusion::pos_<std::allocator<void> > pos;

typedef boost::shared_ptr< ::multisensor_information_fusion::pos > posPtr;
typedef boost::shared_ptr< ::multisensor_information_fusion::pos const> posConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::multisensor_information_fusion::pos_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::multisensor_information_fusion::pos_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace multisensor_information_fusion

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': True, 'IsMessage': True, 'HasHeader': False}
// {'multisensor_information_fusion': ['/home/chenlee/robot_navigation/src/navigation_experiment/multisensor_information_fusion/msg'], 'std_msgs': ['/opt/ros/indigo/share/std_msgs/cmake/../msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::multisensor_information_fusion::pos_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::multisensor_information_fusion::pos_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::multisensor_information_fusion::pos_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::multisensor_information_fusion::pos_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::multisensor_information_fusion::pos_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::multisensor_information_fusion::pos_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::multisensor_information_fusion::pos_<ContainerAllocator> >
{
  static const char* value()
  {
    return "2aa50b4b4ca1cd4fd4d31af99a0968e5";
  }

  static const char* value(const ::multisensor_information_fusion::pos_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x2aa50b4b4ca1cd4fULL;
  static const uint64_t static_value2 = 0xd4d31af99a0968e5ULL;
};

template<class ContainerAllocator>
struct DataType< ::multisensor_information_fusion::pos_<ContainerAllocator> >
{
  static const char* value()
  {
    return "multisensor_information_fusion/pos";
  }

  static const char* value(const ::multisensor_information_fusion::pos_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::multisensor_information_fusion::pos_<ContainerAllocator> >
{
  static const char* value()
  {
    return "float32  x\n\
float32  y\n\
float32  psi\n\
float32  dx\n\
float32  dpsi\n\
\n\
";
  }

  static const char* value(const ::multisensor_information_fusion::pos_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::multisensor_information_fusion::pos_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.x);
      stream.next(m.y);
      stream.next(m.psi);
      stream.next(m.dx);
      stream.next(m.dpsi);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct pos_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::multisensor_information_fusion::pos_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::multisensor_information_fusion::pos_<ContainerAllocator>& v)
  {
    s << indent << "x: ";
    Printer<float>::stream(s, indent + "  ", v.x);
    s << indent << "y: ";
    Printer<float>::stream(s, indent + "  ", v.y);
    s << indent << "psi: ";
    Printer<float>::stream(s, indent + "  ", v.psi);
    s << indent << "dx: ";
    Printer<float>::stream(s, indent + "  ", v.dx);
    s << indent << "dpsi: ";
    Printer<float>::stream(s, indent + "  ", v.dpsi);
  }
};

} // namespace message_operations
} // namespace ros

#endif // MULTISENSOR_INFORMATION_FUSION_MESSAGE_POS_H
