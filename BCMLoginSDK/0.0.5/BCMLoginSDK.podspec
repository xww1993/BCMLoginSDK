Pod::Spec.new do |s|
  s.name             = 'BCMLoginSDK'
  s.version          = '0.0.5'

#这里加上你的工程简介
  s.summary          = 'This is BCMLoginSDK test'

#这里加上你的工程简介
  s.description      = <<-DESC
这是我的一个测试工程，用来演示怎样创建一个源码不公开的静态库
                       DESC

#项目主页，这里可以放上你的静态库的介绍网页
  s.homepage         = 'https://phab.srv.codemao.cn/source/ios_common_spec_repo/'

  s.license          = { :type => 'MIT', :file => 'LICENSE' }

  s.author           = { 'BCMLoginSDK' => 'ppsheep.qian@gmail.com' }

  s.source           = { :git => 'https://github.com/xww1993/BCMLoginSDK.git', :tag => s.version}
 

#最低iOS系统要求
  s.ios.deployment_target = '8.0'

#是否需要项目支持ARC
  s.requires_arc = true

#这个地方注意下，你在工程中要用到的framework,都需要在这里声明，我只是这里列举了几个
#s.frameworks = 'SystemConfiguration', 'MobileCoreServices', 'CoreGraphics', 'Security', 'CoreTelephony'

#在项目中我们还会用到一些library，也需要在这里声明，比如sqllite等tbd结尾的
#s.libraries = 'resolv'

#这里声明的存放源文件的地址，就是我们实际写的代码
# s.source_files = 'BCMLoginSDK/BCMLoginSDK.framework/**/*.h'
 s.vendored_frameworks = 'BCMLoginSDK/BCMLoginSDK.framework'
s.preserve_paths = 'BCMLoginSDK/BCMLoginSDK.framework'
#这里可以用来存放你的资源文件，图片，证书等等
   s.resource_bundles = {
     'BCMLoginSDK' => ['BCMLoginSDK/BCMLoginSDK.framework/*.plist']
   }

#这里声明你需要公开的文件, 有几种声明方式，通配符也支持的，在这里我可以使用通配符PPSPrivateStaticLibrary/Classes/Public/*.h

#s.public_header_files = 'PPSPrivateStaticLibrary/Classes/Public/*.h'
#也可以一个一个写出来[]
#s.public_header_files = ['PPSPrivateStaticLibrary/Classes/Public/PPSPublic1.h',
#                          'PPSPrivateStaticLibrary/Classes/Public/PPSPublic2.h']

#这里可以声明你的静态库依赖的其他静态库
s.dependency 'AFNetworking'
s.dependency 'SAMKeychain'
s.dependency 'UMengUShare/Social/QQ'
s.dependency 'UMengUShare/Social/WeChat'


s.subspec 'BCMLoginSDK_GT3Captcha' do |sss|
sss.vendored_frameworks = 'BCMLoginSDK/GT3Captcha/GT3Captcha.framework'


end
end
